static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
enum V_5 V_6 ;
if ( ! V_4 )
return;
V_6 = V_4 -> V_7 == V_8 ? V_9 : V_10 ;
if ( F_2 ( V_4 -> V_11 ) )
F_3 ( V_4 -> V_11 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_12 * V_4 = (struct V_12 * ) V_2 -> V_4 ;
enum V_5 V_13 , V_14 ;
if ( ! V_4 )
return;
switch ( V_4 -> V_7 ) {
case V_8 :
V_13 = V_9 ;
V_14 = V_9 ;
break;
case V_15 :
V_13 = V_10 ;
V_14 = V_9 ;
break;
case V_16 :
V_13 = V_9 ;
V_14 = V_10 ;
break;
case V_17 :
V_13 = V_10 ;
V_14 = V_10 ;
break;
default:
return;
}
if ( F_2 ( V_4 -> V_11 [ 0 ] ) )
F_3 ( V_4 -> V_11 [ 0 ] , V_13 ) ;
if ( F_2 ( V_4 -> V_11 [ 1 ] ) )
F_3 ( V_4 -> V_11 [ 1 ] , V_14 ) ;
}
static void F_5 ( struct V_1 * V_2 , enum V_18 V_19 )
{
switch ( V_19 ) {
case V_20 :
F_1 ( V_2 ) ;
break;
case V_21 :
F_4 ( V_2 ) ;
break;
default:
break;
}
}
static enum V_22
F_6 ( struct V_1 * V_2 , enum V_18 V_19 )
{
T_1 V_23 , V_24 ;
switch ( V_19 ) {
case V_20 :
V_24 = V_25 ;
break;
case V_21 :
V_24 = V_26 ;
break;
default:
return REGISTER ;
}
F_7 ( V_2 -> V_27 , V_28 , & V_23 ) ;
return V_23 & V_24 ? REGISTER : V_29 ;
}
static bool F_8 ( T_1 V_30 )
{
switch ( V_30 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
return true ;
default:
return false ;
}
}
static T_1 F_9 ( struct V_1 * V_2 ,
enum V_18 V_19 )
{
enum V_22 V_39 = F_6 ( V_2 , V_19 ) ;
struct V_3 * V_40 ;
struct V_12 * V_41 ;
T_1 V_23 , V_42 , V_30 ;
int V_13 , V_14 ;
switch ( V_19 ) {
case V_20 :
if ( V_39 == V_29 ) {
V_40 = (struct V_3 * ) V_2 -> V_4 ;
if ( ! V_40 )
goto V_43;
V_42 = F_10 ( V_40 -> V_11 ) ? 1 : 0 ;
} else {
F_7 ( V_2 -> V_27 , V_28 , & V_23 ) ;
V_42 = ( V_23 & V_44 ) >> V_45 ;
}
V_30 = V_46 [ V_42 ] ;
break;
case V_21 :
if ( V_39 == V_29 ) {
V_41 = (struct V_12 * ) V_2 -> V_4 ;
if ( ! V_41 )
goto V_43;
V_13 = F_10 ( V_41 -> V_11 [ 0 ] ) ;
V_14 = F_10 ( V_41 -> V_11 [ 1 ] ) ;
if ( V_13 == V_47 && V_14 == V_47 )
V_42 = 0 ;
else if ( V_13 == V_47 && V_14 == V_48 )
V_42 = 2 ;
else if ( V_13 == V_48 && V_14 == V_47 )
V_42 = 1 ;
else
V_42 = 3 ;
} else {
F_7 ( V_2 -> V_27 , V_28 , & V_23 ) ;
V_42 = ( V_23 & V_49 ) >> V_50 ;
}
V_30 = V_51 [ V_42 ] ;
break;
default:
goto V_43;
}
return V_30 ;
V_43:
return V_52 ;
}
static int F_11 ( struct V_53 * V_54 ,
unsigned V_55 )
{
struct V_1 * V_2 = F_12 ( V_54 ) ;
enum V_18 V_19 = F_13 ( V_54 ) ;
T_1 V_30 ;
if ( V_2 -> V_4 )
F_5 ( V_2 , V_19 ) ;
V_30 = F_9 ( V_2 , V_19 ) ;
if ( ! F_8 ( V_30 ) )
return - V_56 ;
return F_14 ( V_2 -> V_27 , V_30 , V_57 , V_55 ) ;
}
static int F_15 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_12 ( V_54 ) ;
enum V_18 V_19 = F_13 ( V_54 ) ;
int V_58 ;
T_1 V_23 , V_30 ;
V_30 = F_9 ( V_2 , V_19 ) ;
if ( ! F_8 ( V_30 ) )
return - V_56 ;
V_58 = F_7 ( V_2 -> V_27 , V_30 , & V_23 ) ;
if ( V_58 )
return V_58 ;
return V_23 & V_57 ;
}
static int F_16 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_12 ( V_54 ) ;
enum V_18 V_19 = F_13 ( V_54 ) ;
T_1 V_23 , V_30 = V_59 + V_19 ;
if ( F_7 ( V_2 -> V_27 , V_30 , & V_23 ) )
return - V_56 ;
V_23 = ( V_23 & V_60 ) >> V_61 ;
return V_62 * V_23 ;
}
static int F_17 ( struct V_53 * V_54 , unsigned int V_39 )
{
struct V_1 * V_2 = F_12 ( V_54 ) ;
struct V_63 * V_64 = V_2 -> V_64 ;
T_1 V_23 ;
if ( ! V_64 )
return - V_56 ;
switch ( V_39 ) {
case V_65 :
V_23 = V_66 << V_64 -> V_67 ;
break;
case V_68 :
V_23 = V_69 << V_64 -> V_67 ;
break;
default:
return - V_56 ;
}
return F_14 ( V_2 -> V_27 , V_70 , V_64 -> V_24 , V_23 ) ;
}
static unsigned int F_18 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_12 ( V_54 ) ;
struct V_63 * V_64 = V_2 -> V_64 ;
T_1 V_23 ;
int V_58 ;
if ( ! V_64 )
return - V_56 ;
V_58 = F_7 ( V_2 -> V_27 , V_70 , & V_23 ) ;
if ( V_58 )
return V_58 ;
return V_23 & V_64 -> V_24 ? V_65 : V_68 ;
}
static int F_19 ( struct V_71 * V_27 ,
enum V_18 V_19 )
{
T_1 V_24 , V_23 ;
switch ( V_19 ) {
case V_20 :
V_24 = V_25 ;
V_23 = V_72 ;
break;
case V_21 :
V_24 = V_26 ;
V_23 = V_73 ;
break;
default:
return 0 ;
}
return F_14 ( V_27 , V_28 , V_24 , V_23 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_11 , char * V_74 )
{
struct V_75 * V_76 = V_2 -> V_27 -> V_76 ;
if ( ! F_2 ( V_11 ) ) {
F_21 ( V_76 , L_1 , V_11 ) ;
return - V_56 ;
}
return F_22 ( V_76 , V_11 , V_9 , V_74 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_18 V_19 )
{
struct V_77 * V_78 = V_2 -> V_27 -> V_78 ;
char * V_79 = L_2 ;
char * V_80 [] = { L_3 , L_4 } ;
int V_81 , V_11 , V_58 ;
switch ( V_19 ) {
case V_20 :
V_11 = V_78 -> V_82 -> V_11 ;
V_58 = F_20 ( V_2 , V_11 , V_79 ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_4 = V_78 -> V_82 ;
break;
case V_21 :
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ ) {
V_11 = V_78 -> V_84 -> V_11 [ V_81 ] ;
V_58 = F_20 ( V_2 , V_11 , V_80 [ V_81 ] ) ;
if ( V_58 )
return V_58 ;
}
V_2 -> V_4 = V_78 -> V_84 ;
break;
default:
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , enum V_18 V_19 )
{
struct V_77 * V_78 = V_2 -> V_27 -> V_78 ;
T_1 V_24 [] = { V_25 , V_26 } ;
T_1 V_23 [] = { V_85 , V_86 } ;
if ( V_19 == V_87 || V_19 == V_88 )
return 0 ;
if ( ! V_78 )
goto V_89;
if ( ( V_19 == V_20 && ! V_78 -> V_82 ) ||
( V_19 == V_21 && ! V_78 -> V_84 ) )
goto V_89;
if ( F_23 ( V_2 , V_19 ) )
goto V_89;
return F_14 ( V_2 -> V_27 , V_28 , V_24 [ V_19 ] ,
V_23 [ V_19 ] ) ;
V_89:
return F_19 ( V_2 -> V_27 , V_19 ) ;
}
static T_2 int F_25 ( struct V_90 * V_91 )
{
struct V_71 * V_27 = F_26 ( V_91 -> V_76 . V_92 ) ;
int V_19 = V_91 -> V_19 ;
struct V_1 * V_2 ;
struct V_93 V_94 = { } ;
struct V_53 * V_54 ;
int V_58 ;
V_2 = F_27 ( V_27 -> V_76 , sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_64 = & V_97 [ V_19 ] ;
V_58 = F_24 ( V_2 , V_19 ) ;
if ( V_58 )
return V_58 ;
V_94 . V_76 = V_27 -> V_76 ;
V_94 . V_98 = V_27 -> V_78 ? V_27 -> V_78 -> V_99 [ V_19 ] : NULL ;
V_94 . V_100 = V_2 ;
V_94 . V_101 = V_27 -> V_101 ;
V_54 = F_28 ( & V_102 [ V_19 ] , & V_94 ) ;
if ( F_29 ( V_54 ) ) {
V_58 = F_30 ( V_54 ) ;
F_21 ( V_27 -> V_76 , L_5 ,
V_19 + 1 , V_58 ) ;
return V_58 ;
}
V_2 -> V_103 = V_54 ;
F_31 ( V_91 , V_2 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_33 ( V_91 ) ;
F_31 ( V_91 , NULL ) ;
F_34 ( V_2 -> V_103 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_104 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_104 ) ;
}
