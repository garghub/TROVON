static enum V_1
F_1 ( struct V_2 * V_3 , enum V_4 V_5 )
{
int V_6 ;
T_1 V_7 , V_8 ;
V_6 = F_2 ( V_3 -> V_9 , V_10 , & V_7 ) ;
if ( V_6 )
return V_6 ;
switch ( V_5 ) {
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
case V_14 :
V_8 = V_15 ;
break;
case V_16 :
V_8 = V_17 ;
break;
case V_18 ... V_19 :
V_8 = V_20 ;
break;
case V_21 :
V_8 = V_22 ;
break;
case V_23 :
V_8 = V_24 ;
break;
default:
return REGISTER ;
}
return V_7 & V_8 ? V_25 : REGISTER ;
}
static int F_3 ( struct V_2 * V_3 , int V_26 )
{
struct V_27 * V_28 = V_3 -> V_29 ;
if ( ! V_28 )
return - V_30 ;
if ( F_4 ( V_28 -> V_31 ) )
F_5 ( V_28 -> V_31 , V_26 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = V_3 -> V_29 ;
if ( ! V_28 )
return - V_30 ;
return F_7 ( V_28 -> V_31 ) ? 1 : 0 ;
}
static int F_8 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = F_9 ( V_33 ) ;
enum V_4 V_5 = F_10 ( V_33 ) ;
enum V_1 V_34 = F_1 ( V_3 , V_5 ) ;
switch ( V_34 ) {
case V_25 :
return F_3 ( V_3 , V_35 ) ;
case REGISTER :
return F_11 ( V_33 ) ;
default:
return - V_30 ;
}
}
static int F_12 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = F_9 ( V_33 ) ;
enum V_4 V_5 = F_10 ( V_33 ) ;
enum V_1 V_34 = F_1 ( V_3 , V_5 ) ;
switch ( V_34 ) {
case V_25 :
return F_3 ( V_3 , V_36 ) ;
case REGISTER :
return F_13 ( V_33 ) ;
default:
return - V_30 ;
}
}
static int F_14 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = F_9 ( V_33 ) ;
enum V_4 V_5 = F_10 ( V_33 ) ;
enum V_1 V_34 = F_1 ( V_3 , V_5 ) ;
switch ( V_34 ) {
case V_25 :
return F_6 ( V_3 ) ;
case REGISTER :
return F_15 ( V_33 ) ;
default:
return - V_30 ;
}
}
static int F_16 ( struct V_32 * V_33 )
{
struct V_2 * V_3 = F_9 ( V_33 ) ;
enum V_4 V_5 = F_10 ( V_33 ) ;
T_1 V_7 , V_37 = V_38 + V_5 ;
if ( F_2 ( V_3 -> V_9 , V_37 , & V_7 ) )
return - V_30 ;
V_7 = ( V_7 & V_39 ) >> V_40 ;
return V_41 * V_7 ;
}
static int F_17 ( struct V_32 * V_33 )
{
enum V_4 V_5 = F_10 ( V_33 ) ;
switch ( V_5 ) {
case V_18 ... V_21 :
return 2850000 ;
case V_42 :
case V_43 ... V_44 :
return 2500000 ;
case V_45 :
return 1100000 ;
default:
return - V_30 ;
}
}
static int F_18 ( struct V_2 * V_3 ,
enum V_46 V_5 )
{
struct V_47 * V_48 = V_3 -> V_9 -> V_48 ;
struct V_27 * V_28 = V_3 -> V_29 ;
int V_6 , V_31 , V_26 ;
char * V_49 [] = {
[ V_50 ] = L_1 ,
[ V_51 ] = L_2 ,
[ V_52 ] = L_3 ,
[ V_53 ] = L_4 ,
[ V_54 ] = L_5 ,
[ V_55 ] = L_6 ,
} ;
V_31 = V_28 -> V_31 ;
if ( ! F_4 ( V_31 ) ) {
F_19 ( V_48 , L_7 , V_31 ) ;
return - V_30 ;
}
V_26 = V_28 -> V_56 ;
V_6 = F_20 ( V_48 , V_31 , V_26 , V_49 [ V_5 ] ) ;
if ( V_6 == - V_57 ) {
F_21 ( V_48 , L_8 , V_31 ) ;
return 0 ;
}
return V_6 ;
}
static int F_22 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
int V_6 ;
struct V_58 * V_9 = V_3 -> V_9 ;
struct V_59 * V_60 = V_9 -> V_60 ;
enum V_46 V_61 ;
T_1 V_62 [] = {
[ V_50 ] = V_17 ,
[ V_51 ] = V_20 ,
[ V_52 ] = V_22 ,
[ V_53 ] = V_24 ,
[ V_54 ] = V_12 ,
[ V_55 ] = V_15 ,
} ;
T_1 V_7 [] = {
[ V_50 ] = 0 << 5 ,
[ V_51 ] = 0 << 4 ,
[ V_52 ] = 0 << 3 ,
[ V_53 ] = 0 << 2 ,
[ V_54 ] = 0 << 1 ,
[ V_55 ] = 0 << 0 ,
} ;
switch ( V_5 ) {
case V_11 :
V_61 = V_54 ;
break;
case V_13 :
case V_14 :
V_61 = V_55 ;
break;
case V_16 :
V_61 = V_50 ;
break;
case V_18 ... V_19 :
V_61 = V_51 ;
break;
case V_21 :
V_61 = V_52 ;
break;
case V_23 :
V_61 = V_53 ;
break;
default:
return 0 ;
}
if ( ! V_60 || ! V_60 -> V_63 || ! V_60 -> V_63 [ V_61 ] )
goto V_64;
V_3 -> V_29 = V_60 -> V_63 [ V_61 ] ;
V_6 = F_18 ( V_3 , V_61 ) ;
if ( V_6 )
goto V_64;
return V_6 ;
V_64:
return F_23 ( V_9 , V_10 , V_62 [ V_61 ] ,
V_7 [ V_61 ] ) ;
}
static T_2 int F_24 ( struct V_65 * V_66 )
{
struct V_58 * V_9 = F_25 ( V_66 -> V_48 . V_67 ) ;
int V_5 = V_66 -> V_5 ;
struct V_2 * V_3 ;
struct V_68 V_69 = { } ;
struct V_32 * V_33 ;
int V_6 ;
V_3 = F_26 ( V_9 -> V_48 , sizeof( struct V_2 ) , V_70 ) ;
if ( ! V_3 )
return - V_71 ;
V_3 -> V_9 = V_9 ;
V_6 = F_22 ( V_3 , V_72 [ V_5 ] ) ;
if ( V_6 )
return V_6 ;
V_69 . V_48 = V_9 -> V_48 ;
V_69 . V_73 = V_9 -> V_60 ? V_9 -> V_60 -> V_74 [ V_5 ] : NULL ;
V_69 . V_75 = V_3 ;
V_69 . V_76 = V_9 -> V_76 ;
V_33 = F_27 ( & V_77 [ V_5 ] , & V_69 ) ;
if ( F_28 ( V_33 ) ) {
V_6 = F_29 ( V_33 ) ;
F_19 ( V_9 -> V_48 , L_9 ,
V_5 + 1 , V_6 ) ;
return V_6 ;
}
V_3 -> V_78 = V_33 ;
F_30 ( V_66 , V_3 ) ;
return 0 ;
}
static int T_3 F_31 ( struct V_65 * V_66 )
{
struct V_2 * V_3 = F_32 ( V_66 ) ;
F_30 ( V_66 , NULL ) ;
F_33 ( V_3 -> V_78 ) ;
return 0 ;
}
static T_2 int F_34 ( struct V_65 * V_66 )
{
struct V_58 * V_9 = F_25 ( V_66 -> V_48 . V_67 ) ;
int V_5 = V_66 -> V_5 ;
struct V_2 * V_3 ;
struct V_68 V_69 = { } ;
struct V_32 * V_33 ;
int V_6 ;
V_3 = F_26 ( V_9 -> V_48 , sizeof( struct V_2 ) , V_70 ) ;
if ( ! V_3 )
return - V_71 ;
V_3 -> V_9 = V_9 ;
V_6 = F_22 ( V_3 , V_79 [ V_5 ] ) ;
if ( V_6 )
return V_6 ;
V_69 . V_48 = V_9 -> V_48 ;
V_69 . V_73 = V_9 -> V_60 ? V_9 -> V_60 -> V_80 [ V_5 ] : NULL ;
V_69 . V_75 = V_3 ;
V_69 . V_76 = V_9 -> V_76 ;
V_33 = F_27 ( & V_81 [ V_5 ] , & V_69 ) ;
if ( F_28 ( V_33 ) ) {
V_6 = F_29 ( V_33 ) ;
F_19 ( V_9 -> V_48 , L_10 ,
V_5 + 1 , V_6 ) ;
return V_6 ;
}
V_3 -> V_78 = V_33 ;
F_30 ( V_66 , V_3 ) ;
return 0 ;
}
static int T_3 F_35 ( struct V_65 * V_66 )
{
struct V_2 * V_3 = F_32 ( V_66 ) ;
F_30 ( V_66 , NULL ) ;
F_33 ( V_3 -> V_78 ) ;
return 0 ;
}
static int T_4 F_36 ( void )
{
int V_6 ;
V_6 = F_37 ( & V_82 ) ;
if ( V_6 )
return V_6 ;
return F_37 ( & V_83 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_83 ) ;
F_39 ( & V_82 ) ;
}
