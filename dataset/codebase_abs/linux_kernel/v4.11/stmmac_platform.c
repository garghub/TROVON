static int F_1 ( int V_1 )
{
int V_2 = V_1 ;
switch ( V_2 ) {
case V_3 :
case 128 :
case 256 :
break;
default:
V_2 = 0 ;
F_2 ( L_1 ,
V_1 ) ;
break;
}
return V_2 ;
}
static int F_3 ( int V_4 )
{
int V_2 = V_4 ;
switch ( V_2 ) {
case 1 :
case 32 :
case 64 :
case 128 :
break;
default:
V_2 = 1 ;
F_2 ( L_2 ,
V_4 ) ;
break;
}
return V_2 ;
}
static struct V_5 * F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_5 * V_10 ;
V_9 = F_5 ( V_7 -> V_11 . V_12 , L_3 , 0 ) ;
if ( ! V_9 )
return NULL ;
V_10 = F_6 ( sizeof( * V_10 ) , V_13 ) ;
if ( ! V_10 ) {
F_7 ( V_9 ) ;
return F_8 ( - V_14 ) ;
}
V_10 -> V_15 = F_9 ( V_9 , L_4 ) ;
V_10 -> V_16 = F_9 ( V_9 , L_5 ) ;
V_10 -> V_17 = F_9 ( V_9 , L_6 ) ;
V_10 -> V_18 = F_9 ( V_9 , L_7 ) ;
V_10 -> V_19 = F_9 ( V_9 , L_8 ) ;
V_10 -> V_20 = F_9 ( V_9 , L_9 ) ;
if ( F_10 ( V_9 , L_10 , & V_10 -> V_21 ) )
V_10 -> V_21 = 1 ;
if ( F_10 ( V_9 , L_11 , & V_10 -> V_22 ) )
V_10 -> V_22 = 1 ;
F_11 ( V_9 , L_12 , V_10 -> V_23 , V_24 ) ;
F_7 ( V_9 ) ;
return V_10 ;
}
static int F_12 ( struct V_25 * V_26 ,
struct V_8 * V_9 , struct V_27 * V_11 )
{
bool V_28 = true ;
V_26 -> V_29 = F_5 ( V_9 , L_13 , 0 ) ;
if ( V_26 -> V_29 )
F_13 ( V_11 , L_14 ) ;
if ( ! V_26 -> V_29 && F_14 ( V_9 ) ) {
if ( ( F_15 ( V_9 ) < 0 ) )
return - V_30 ;
F_13 ( V_11 , L_15 ) ;
V_26 -> V_29 = F_16 ( V_9 ) ;
V_28 = false ;
}
if ( F_17 ( V_9 , L_16 ) ) {
V_26 -> V_31 = F_18 ( V_9 , L_17 ) ;
} else {
F_19 (np, plat->mdio_node) {
if ( F_17 ( V_26 -> V_31 ,
L_18 ) )
break;
}
}
if ( V_26 -> V_31 ) {
F_13 ( V_11 , L_19 ) ;
V_28 = true ;
}
if ( V_28 )
V_26 -> V_32 =
F_20 ( V_11 , sizeof( struct V_33 ) ,
V_13 ) ;
return 0 ;
}
struct V_25 *
F_21 ( struct V_6 * V_7 , const char * * V_34 )
{
struct V_8 * V_9 = V_7 -> V_11 . V_12 ;
struct V_25 * V_26 ;
struct V_35 * V_36 ;
V_26 = F_20 ( & V_7 -> V_11 , sizeof( * V_26 ) , V_13 ) ;
if ( ! V_26 )
return F_8 ( - V_14 ) ;
* V_34 = F_22 ( V_9 ) ;
V_26 -> V_37 = F_23 ( V_9 ) ;
if ( F_10 ( V_9 , L_20 , & V_26 -> V_38 ) )
V_26 -> V_38 = - 1 ;
V_26 -> V_39 = F_24 ( V_9 , L_21 ) ;
if ( V_26 -> V_39 < 0 )
V_26 -> V_39 = 0 ;
V_26 -> V_40 = - 1 ;
if ( F_10 ( V_9 , L_22 , & V_26 -> V_40 ) == 0 )
F_25 ( & V_7 -> V_11 , L_23 ) ;
if ( F_12 ( V_26 , V_9 , & V_7 -> V_11 ) )
return F_8 ( - V_30 ) ;
F_10 ( V_9 , L_24 , & V_26 -> V_41 ) ;
F_10 ( V_9 , L_25 , & V_26 -> V_42 ) ;
V_26 -> V_43 =
F_9 ( V_9 , L_26 ) ;
V_26 -> V_44 =
F_9 ( V_9 , L_27 ) ;
V_26 -> V_45 = V_46 ;
V_26 -> V_47 = V_3 ;
V_26 -> V_48 = 1 ;
if ( F_17 ( V_9 , L_28 ) ||
F_17 ( V_9 , L_29 ) ||
F_17 ( V_9 , L_30 ) ||
F_17 ( V_9 , L_31 ) ) {
F_10 ( V_9 , L_32 , & V_26 -> V_45 ) ;
F_10 ( V_9 , L_33 ,
& V_26 -> V_47 ) ;
F_10 ( V_9 , L_34 ,
& V_26 -> V_48 ) ;
V_26 -> V_48 = F_3 (
V_26 -> V_48 ) ;
V_26 -> V_47 = F_1 (
V_26 -> V_47 ) ;
V_26 -> V_49 = 1 ;
V_26 -> V_50 = 1 ;
}
if ( F_17 ( V_9 , L_35 ) ||
F_17 ( V_9 , L_36 ) ) {
V_26 -> V_51 = 1 ;
V_26 -> V_49 = 0 ;
V_26 -> V_50 = 1 ;
V_26 -> V_52 = F_9 ( V_9 , L_37 ) ;
}
if ( F_17 ( V_9 , L_38 ) ||
F_17 ( V_9 , L_39 ) ) {
V_26 -> V_53 = 1 ;
V_26 -> V_54 = 1 ;
V_26 -> V_43 = 1 ;
}
V_36 = F_20 ( & V_7 -> V_11 , sizeof( * V_36 ) ,
V_13 ) ;
if ( ! V_36 ) {
F_26 ( V_7 , V_26 ) ;
return F_8 ( - V_14 ) ;
}
V_26 -> V_36 = V_36 ;
F_10 ( V_9 , L_40 , & V_36 -> V_55 ) ;
if ( ! V_36 -> V_55 )
V_36 -> V_55 = V_56 ;
F_10 ( V_9 , L_41 , & V_36 -> V_57 ) ;
F_10 ( V_9 , L_42 , & V_36 -> V_58 ) ;
V_36 -> V_59 = ! F_9 ( V_9 , L_43 ) ;
V_36 -> V_60 = F_9 ( V_9 , L_44 ) ;
V_36 -> V_61 = F_9 ( V_9 , L_45 ) ;
V_36 -> V_62 = F_9 ( V_9 , L_46 ) ;
V_26 -> V_63 = F_9 ( V_9 , L_47 ) ;
if ( V_26 -> V_63 ) {
V_26 -> V_43 = 0 ;
F_27 ( L_48 ) ;
}
F_10 ( V_9 , L_49 , & V_26 -> V_64 ) ;
V_26 -> V_10 = F_4 ( V_7 ) ;
V_26 -> V_65 = F_28 ( & V_7 -> V_11 ,
V_66 ) ;
if ( F_29 ( V_26 -> V_65 ) ) {
F_25 ( & V_7 -> V_11 , L_50 ) ;
V_26 -> V_65 = NULL ;
}
F_30 ( V_26 -> V_65 ) ;
V_26 -> V_67 = F_28 ( & V_7 -> V_11 , L_51 ) ;
if ( F_29 ( V_26 -> V_67 ) ) {
if ( F_31 ( V_26 -> V_67 ) == - V_68 )
goto V_69;
V_26 -> V_67 = NULL ;
}
F_30 ( V_26 -> V_67 ) ;
V_26 -> V_70 = F_28 ( & V_7 -> V_11 , L_52 ) ;
if ( F_29 ( V_26 -> V_70 ) ) {
V_26 -> V_71 = F_32 ( V_26 -> V_65 ) ;
V_26 -> V_70 = NULL ;
F_25 ( & V_7 -> V_11 , L_53 ) ;
} else {
F_30 ( V_26 -> V_70 ) ;
V_26 -> V_71 = F_32 ( V_26 -> V_70 ) ;
F_13 ( & V_7 -> V_11 , L_54 , V_26 -> V_71 ) ;
}
V_26 -> V_72 = F_33 ( & V_7 -> V_11 ,
V_66 ) ;
if ( F_29 ( V_26 -> V_72 ) ) {
if ( F_31 ( V_26 -> V_72 ) == - V_68 )
goto V_73;
F_34 ( & V_7 -> V_11 , L_55 ) ;
V_26 -> V_72 = NULL ;
}
return V_26 ;
V_73:
F_35 ( V_26 -> V_67 ) ;
V_69:
F_35 ( V_26 -> V_65 ) ;
return F_8 ( - V_68 ) ;
}
void F_26 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_7 -> V_11 . V_12 ;
if ( F_14 ( V_9 ) )
F_36 ( V_9 ) ;
F_7 ( V_26 -> V_29 ) ;
F_7 ( V_26 -> V_31 ) ;
}
struct V_25 *
F_21 ( struct V_6 * V_7 , const char * * V_34 )
{
return F_8 ( - V_74 ) ;
}
void F_26 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
}
int F_37 ( struct V_6 * V_7 ,
struct V_75 * V_76 )
{
struct V_77 * V_78 ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_79 = F_38 ( V_7 , L_56 ) ;
if ( V_76 -> V_79 < 0 ) {
if ( V_76 -> V_79 != - V_68 ) {
F_39 ( & V_7 -> V_11 ,
L_57 ) ;
}
return V_76 -> V_79 ;
}
V_76 -> V_80 = F_38 ( V_7 , L_58 ) ;
if ( V_76 -> V_80 < 0 ) {
if ( V_76 -> V_80 == - V_68 )
return - V_68 ;
V_76 -> V_80 = V_76 -> V_79 ;
}
V_76 -> V_81 = F_38 ( V_7 , L_59 ) ;
if ( V_76 -> V_81 == - V_68 )
return - V_68 ;
V_78 = F_40 ( V_7 , V_82 , 0 ) ;
V_76 -> V_83 = F_41 ( & V_7 -> V_11 , V_78 ) ;
return F_42 ( V_76 -> V_83 ) ;
}
int F_43 ( struct V_6 * V_7 )
{
struct V_84 * V_85 = F_44 ( V_7 ) ;
struct V_86 * V_87 = F_45 ( V_85 ) ;
struct V_25 * V_26 = V_87 -> V_26 ;
int V_88 = F_46 ( & V_7 -> V_11 ) ;
if ( V_26 -> exit )
V_26 -> exit ( V_7 , V_26 -> V_89 ) ;
F_26 ( V_7 , V_26 ) ;
return V_88 ;
}
static int F_47 ( struct V_27 * V_11 )
{
int V_88 ;
struct V_84 * V_85 = F_48 ( V_11 ) ;
struct V_86 * V_87 = F_45 ( V_85 ) ;
struct V_6 * V_7 = F_49 ( V_11 ) ;
V_88 = F_50 ( V_11 ) ;
if ( V_87 -> V_26 -> exit )
V_87 -> V_26 -> exit ( V_7 , V_87 -> V_26 -> V_89 ) ;
return V_88 ;
}
static int F_51 ( struct V_27 * V_11 )
{
struct V_84 * V_85 = F_48 ( V_11 ) ;
struct V_86 * V_87 = F_45 ( V_85 ) ;
struct V_6 * V_7 = F_49 ( V_11 ) ;
if ( V_87 -> V_26 -> V_90 )
V_87 -> V_26 -> V_90 ( V_7 , V_87 -> V_26 -> V_89 ) ;
return F_52 ( V_11 ) ;
}
