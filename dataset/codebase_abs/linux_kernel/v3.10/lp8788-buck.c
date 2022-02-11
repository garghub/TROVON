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
V_30 = V_31 + V_42 ;
break;
case V_21 :
if ( V_39 == V_29 ) {
V_41 = (struct V_12 * ) V_2 -> V_4 ;
if ( ! V_41 )
goto V_43;
V_13 = F_10 ( V_41 -> V_11 [ 0 ] ) ;
V_14 = F_10 ( V_41 -> V_11 [ 1 ] ) ;
if ( V_13 == V_46 && V_14 == V_46 )
V_42 = 0 ;
else if ( V_13 == V_46 && V_14 == V_47 )
V_42 = 2 ;
else if ( V_13 == V_47 && V_14 == V_46 )
V_42 = 1 ;
else
V_42 = 3 ;
} else {
F_7 ( V_2 -> V_27 , V_28 , & V_23 ) ;
V_42 = ( V_23 & V_48 ) >> V_49 ;
}
V_30 = V_35 + V_42 ;
break;
default:
goto V_43;
}
return V_30 ;
V_43:
return V_50 ;
}
static int F_11 ( struct V_51 * V_52 ,
unsigned V_53 )
{
struct V_1 * V_2 = F_12 ( V_52 ) ;
enum V_18 V_19 = F_13 ( V_52 ) ;
T_1 V_30 ;
if ( V_2 -> V_4 )
F_5 ( V_2 , V_19 ) ;
V_30 = F_9 ( V_2 , V_19 ) ;
if ( ! F_8 ( V_30 ) )
return - V_54 ;
return F_14 ( V_2 -> V_27 , V_30 , V_55 , V_53 ) ;
}
static int F_15 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_12 ( V_52 ) ;
enum V_18 V_19 = F_13 ( V_52 ) ;
int V_56 ;
T_1 V_23 , V_30 ;
V_30 = F_9 ( V_2 , V_19 ) ;
if ( ! F_8 ( V_30 ) )
return - V_54 ;
V_56 = F_7 ( V_2 -> V_27 , V_30 , & V_23 ) ;
if ( V_56 )
return V_56 ;
return V_23 & V_55 ;
}
static int F_16 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_12 ( V_52 ) ;
enum V_18 V_19 = F_13 ( V_52 ) ;
T_1 V_23 , V_30 = V_57 + V_19 ;
if ( F_7 ( V_2 -> V_27 , V_30 , & V_23 ) )
return - V_54 ;
V_23 = ( V_23 & V_58 ) >> V_59 ;
return V_60 * V_23 ;
}
static int F_17 ( struct V_51 * V_52 , unsigned int V_39 )
{
struct V_1 * V_2 = F_12 ( V_52 ) ;
enum V_18 V_19 = F_13 ( V_52 ) ;
T_1 V_24 , V_23 ;
V_24 = F_18 ( V_19 ) ;
switch ( V_39 ) {
case V_61 :
V_23 = V_62 << F_19 ( V_19 ) ;
break;
case V_63 :
V_23 = V_64 << F_19 ( V_19 ) ;
break;
default:
return - V_54 ;
}
return F_14 ( V_2 -> V_27 , V_65 , V_24 , V_23 ) ;
}
static unsigned int F_20 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_12 ( V_52 ) ;
enum V_18 V_19 = F_13 ( V_52 ) ;
T_1 V_23 ;
int V_56 ;
V_56 = F_7 ( V_2 -> V_27 , V_65 , & V_23 ) ;
if ( V_56 )
return V_56 ;
return V_23 & F_18 ( V_19 ) ?
V_61 : V_63 ;
}
static int F_21 ( struct V_66 * V_67 ,
struct V_1 * V_2 ,
enum V_18 V_19 )
{
struct V_68 * V_69 = V_2 -> V_27 -> V_69 ;
char * V_70 = L_1 ;
char * V_71 [] = { L_2 , L_3 } ;
int V_72 , V_11 , V_56 ;
switch ( V_19 ) {
case V_20 :
V_11 = V_69 -> V_73 -> V_11 ;
V_56 = F_22 ( & V_67 -> V_74 , V_11 , V_9 ,
V_70 ) ;
if ( V_56 )
return V_56 ;
V_2 -> V_4 = V_69 -> V_73 ;
break;
case V_21 :
for ( V_72 = 0 ; V_72 < V_75 ; V_72 ++ ) {
V_11 = V_69 -> V_76 -> V_11 [ V_72 ] ;
V_56 = F_22 ( & V_67 -> V_74 , V_11 ,
V_9 , V_71 [ V_72 ] ) ;
if ( V_56 )
return V_56 ;
}
V_2 -> V_4 = V_69 -> V_76 ;
break;
default:
break;
}
return 0 ;
}
static int F_23 ( struct V_66 * V_67 ,
struct V_1 * V_2 , enum V_18 V_19 )
{
struct V_68 * V_69 = V_2 -> V_27 -> V_69 ;
T_1 V_24 [] = { V_25 , V_26 } ;
T_1 V_23 [] = { V_77 , V_78 } ;
T_1 V_79 [] = { V_80 , V_81 } ;
if ( V_19 > V_21 )
return 0 ;
if ( ! V_69 )
goto V_82;
if ( ( V_19 == V_20 && ! V_69 -> V_73 ) ||
( V_19 == V_21 && ! V_69 -> V_76 ) )
goto V_82;
if ( F_21 ( V_67 , V_2 , V_19 ) )
goto V_82;
return F_14 ( V_2 -> V_27 , V_28 , V_24 [ V_19 ] ,
V_23 [ V_19 ] ) ;
V_82:
return F_14 ( V_2 -> V_27 , V_28 , V_24 [ V_19 ] ,
V_79 [ V_19 ] ) ;
}
static int F_24 ( struct V_66 * V_67 )
{
struct V_83 * V_27 = F_25 ( V_67 -> V_74 . V_84 ) ;
int V_19 = V_67 -> V_19 ;
struct V_1 * V_2 ;
struct V_85 V_86 = { } ;
struct V_51 * V_52 ;
int V_56 ;
if ( V_19 >= V_87 )
return - V_54 ;
V_2 = F_26 ( & V_67 -> V_74 , sizeof( struct V_1 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
V_2 -> V_27 = V_27 ;
V_56 = F_23 ( V_67 , V_2 , V_19 ) ;
if ( V_56 )
return V_56 ;
V_86 . V_74 = V_67 -> V_74 . V_84 ;
V_86 . V_90 = V_27 -> V_69 ? V_27 -> V_69 -> V_91 [ V_19 ] : NULL ;
V_86 . V_92 = V_2 ;
V_86 . V_93 = V_27 -> V_93 ;
V_52 = F_27 ( & V_94 [ V_19 ] , & V_86 ) ;
if ( F_28 ( V_52 ) ) {
V_56 = F_29 ( V_52 ) ;
F_30 ( & V_67 -> V_74 , L_4 ,
V_19 + 1 , V_56 ) ;
return V_56 ;
}
V_2 -> V_95 = V_52 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_31 ( V_67 , NULL ) ;
F_34 ( V_2 -> V_95 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_96 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_96 ) ;
}
