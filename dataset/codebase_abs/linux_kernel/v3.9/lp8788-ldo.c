static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 ) {
F_3 ( V_4 -> V_5 -> V_6 , V_7 ) ;
return 0 ;
} else {
return F_4 ( V_2 ) ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 ) {
F_3 ( V_4 -> V_5 -> V_6 , V_8 ) ;
return 0 ;
} else {
return F_6 ( V_2 ) ;
}
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
return F_8 ( V_4 -> V_5 -> V_6 ) ? 1 : 0 ;
else
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_9 V_10 = F_11 ( V_2 ) ;
T_1 V_11 , V_12 = V_13 + V_10 ;
if ( F_12 ( V_4 -> V_14 , V_12 , & V_11 ) )
return - V_15 ;
V_11 = ( V_11 & V_16 ) >> V_17 ;
return V_18 * V_11 ;
}
static int F_13 ( struct V_1 * V_2 )
{
enum V_9 V_10 = F_11 ( V_2 ) ;
switch ( V_10 ) {
case V_19 ... V_20 :
return 2850000 ;
case V_21 :
case V_22 ... V_23 :
return 2500000 ;
case V_24 :
return 1100000 ;
default:
return - V_15 ;
}
}
static int F_14 ( struct V_25 * V_26 ,
struct V_3 * V_4 ,
enum V_27 V_10 )
{
struct V_28 * V_29 = & V_26 -> V_29 ;
struct V_30 * V_31 = V_4 -> V_5 ;
int V_32 , V_6 , V_33 ;
char * V_34 [] = {
[ V_35 ] = L_1 ,
[ V_36 ] = L_2 ,
[ V_37 ] = L_3 ,
[ V_38 ] = L_4 ,
[ V_39 ] = L_5 ,
[ V_40 ] = L_6 ,
} ;
V_6 = V_31 -> V_6 ;
if ( ! F_15 ( V_6 ) ) {
F_16 ( V_29 , L_7 , V_6 ) ;
return - V_15 ;
}
V_33 = V_31 -> V_41 ;
V_32 = F_17 ( V_29 , V_6 , V_33 , V_34 [ V_10 ] ) ;
if ( V_32 == - V_42 ) {
F_18 ( V_29 , L_8 , V_6 ) ;
return 0 ;
}
return V_32 ;
}
static int F_19 ( struct V_25 * V_26 ,
struct V_3 * V_4 ,
enum V_9 V_10 )
{
int V_32 ;
struct V_43 * V_14 = V_4 -> V_14 ;
struct V_44 * V_45 = V_14 -> V_45 ;
enum V_27 V_46 ;
T_1 V_47 [] = {
[ V_35 ] = V_48 ,
[ V_36 ] = V_49 ,
[ V_37 ] = V_50 ,
[ V_38 ] = V_51 ,
[ V_39 ] = V_52 ,
[ V_40 ] = V_53 ,
} ;
switch ( V_10 ) {
case V_54 :
V_46 = V_39 ;
break;
case V_55 :
case V_56 :
V_46 = V_40 ;
break;
case V_57 :
V_46 = V_35 ;
break;
case V_19 ... V_58 :
V_46 = V_36 ;
break;
case V_20 :
V_46 = V_37 ;
break;
case V_59 :
V_46 = V_38 ;
break;
default:
return 0 ;
}
if ( ! V_45 || ! V_45 -> V_60 || ! V_45 -> V_60 [ V_46 ] )
goto V_61;
V_4 -> V_5 = V_45 -> V_60 [ V_46 ] ;
V_32 = F_14 ( V_26 , V_4 , V_46 ) ;
if ( V_32 ) {
V_4 -> V_5 = NULL ;
goto V_61;
}
return V_32 ;
V_61:
return F_20 ( V_14 , V_62 , V_47 [ V_46 ] , 0 ) ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_43 * V_14 = F_22 ( V_26 -> V_29 . V_63 ) ;
int V_10 = V_26 -> V_10 ;
struct V_3 * V_4 ;
struct V_64 V_65 = { } ;
struct V_1 * V_2 ;
int V_32 ;
V_4 = F_23 ( & V_26 -> V_29 , sizeof( struct V_3 ) , V_66 ) ;
if ( ! V_4 )
return - V_67 ;
V_4 -> V_14 = V_14 ;
V_32 = F_19 ( V_26 , V_4 , V_68 [ V_10 ] ) ;
if ( V_32 )
return V_32 ;
V_65 . V_29 = V_26 -> V_29 . V_63 ;
V_65 . V_69 = V_14 -> V_45 ? V_14 -> V_45 -> V_70 [ V_10 ] : NULL ;
V_65 . V_71 = V_4 ;
V_65 . V_72 = V_14 -> V_72 ;
V_2 = F_24 ( & V_73 [ V_10 ] , & V_65 ) ;
if ( F_25 ( V_2 ) ) {
V_32 = F_26 ( V_2 ) ;
F_16 ( & V_26 -> V_29 , L_9 ,
V_10 + 1 , V_32 ) ;
return V_32 ;
}
V_4 -> V_74 = V_2 ;
F_27 ( V_26 , V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_29 ( V_26 ) ;
F_27 ( V_26 , NULL ) ;
F_30 ( V_4 -> V_74 ) ;
return 0 ;
}
static int F_31 ( struct V_25 * V_26 )
{
struct V_43 * V_14 = F_22 ( V_26 -> V_29 . V_63 ) ;
int V_10 = V_26 -> V_10 ;
struct V_3 * V_4 ;
struct V_64 V_65 = { } ;
struct V_1 * V_2 ;
int V_32 ;
V_4 = F_23 ( & V_26 -> V_29 , sizeof( struct V_3 ) , V_66 ) ;
if ( ! V_4 )
return - V_67 ;
V_4 -> V_14 = V_14 ;
V_32 = F_19 ( V_26 , V_4 , V_75 [ V_10 ] ) ;
if ( V_32 )
return V_32 ;
V_65 . V_29 = V_26 -> V_29 . V_63 ;
V_65 . V_69 = V_14 -> V_45 ? V_14 -> V_45 -> V_76 [ V_10 ] : NULL ;
V_65 . V_71 = V_4 ;
V_65 . V_72 = V_14 -> V_72 ;
V_2 = F_24 ( & V_77 [ V_10 ] , & V_65 ) ;
if ( F_25 ( V_2 ) ) {
V_32 = F_26 ( V_2 ) ;
F_16 ( & V_26 -> V_29 , L_10 ,
V_10 + 1 , V_32 ) ;
return V_32 ;
}
V_4 -> V_74 = V_2 ;
F_27 ( V_26 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_29 ( V_26 ) ;
F_27 ( V_26 , NULL ) ;
F_30 ( V_4 -> V_74 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
int V_32 ;
V_32 = F_34 ( & V_78 ) ;
if ( V_32 )
return V_32 ;
return F_34 ( & V_79 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_79 ) ;
F_36 ( & V_78 ) ;
}
