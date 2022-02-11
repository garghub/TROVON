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
V_10 -> V_21 = F_9 ( V_9 , L_10 ) ;
if ( F_10 ( V_9 , L_11 , & V_10 -> V_22 ) )
V_10 -> V_22 = 1 ;
if ( F_10 ( V_9 , L_12 , & V_10 -> V_23 ) )
V_10 -> V_23 = 1 ;
F_11 ( V_9 , L_13 , V_10 -> V_24 , V_25 ) ;
F_7 ( V_9 ) ;
return V_10 ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_8 * V_9 , struct V_28 * V_11 )
{
bool V_29 = true ;
V_27 -> V_30 = F_5 ( V_9 , L_14 , 0 ) ;
if ( V_27 -> V_30 )
F_13 ( V_11 , L_15 ) ;
if ( ! V_27 -> V_30 && F_14 ( V_9 ) ) {
if ( ( F_15 ( V_9 ) < 0 ) )
return - V_31 ;
F_13 ( V_11 , L_16 ) ;
V_27 -> V_30 = F_16 ( V_9 ) ;
V_29 = false ;
}
F_17 (np, plat->mdio_node) {
if ( F_18 ( V_27 -> V_32 , L_17 ) )
break;
}
if ( V_27 -> V_32 ) {
F_13 ( V_11 , L_18 ) ;
V_29 = true ;
}
if ( V_29 )
V_27 -> V_33 =
F_19 ( V_11 , sizeof( struct V_34 ) ,
V_13 ) ;
return 0 ;
}
struct V_26 *
F_20 ( struct V_6 * V_7 , const char * * V_35 )
{
struct V_8 * V_9 = V_7 -> V_11 . V_12 ;
struct V_26 * V_27 ;
struct V_36 * V_37 ;
V_27 = F_19 ( & V_7 -> V_11 , sizeof( * V_27 ) , V_13 ) ;
if ( ! V_27 )
return F_8 ( - V_14 ) ;
* V_35 = F_21 ( V_9 ) ;
V_27 -> V_38 = F_22 ( V_9 ) ;
if ( F_10 ( V_9 , L_19 , & V_27 -> V_39 ) )
V_27 -> V_39 = - 1 ;
V_27 -> V_40 = F_23 ( V_9 , L_20 ) ;
if ( V_27 -> V_40 < 0 )
V_27 -> V_40 = 0 ;
V_27 -> V_41 = - 1 ;
if ( F_10 ( V_9 , L_21 , & V_27 -> V_41 ) == 0 )
F_24 ( & V_7 -> V_11 , L_22 ) ;
if ( F_12 ( V_27 , V_9 , & V_7 -> V_11 ) )
return F_8 ( - V_31 ) ;
F_10 ( V_9 , L_23 , & V_27 -> V_42 ) ;
F_10 ( V_9 , L_24 , & V_27 -> V_43 ) ;
V_27 -> V_44 =
F_9 ( V_9 , L_25 ) ;
V_27 -> V_45 = V_46 ;
V_27 -> V_47 = V_3 ;
V_27 -> V_48 = 1 ;
if ( F_18 ( V_9 , L_26 ) ||
F_18 ( V_9 , L_27 ) ||
F_18 ( V_9 , L_28 ) ||
F_18 ( V_9 , L_29 ) ) {
F_10 ( V_9 , L_30 , & V_27 -> V_45 ) ;
F_10 ( V_9 , L_31 ,
& V_27 -> V_47 ) ;
F_10 ( V_9 , L_32 ,
& V_27 -> V_48 ) ;
V_27 -> V_48 = F_3 (
V_27 -> V_48 ) ;
V_27 -> V_47 = F_1 (
V_27 -> V_47 ) ;
V_27 -> V_49 = 1 ;
V_27 -> V_50 = 1 ;
}
if ( F_18 ( V_9 , L_33 ) ||
F_18 ( V_9 , L_34 ) ) {
V_27 -> V_51 = 1 ;
V_27 -> V_49 = 0 ;
V_27 -> V_50 = 1 ;
V_27 -> V_52 = F_9 ( V_9 , L_35 ) ;
}
if ( F_18 ( V_9 , L_36 ) ||
F_18 ( V_9 , L_37 ) ) {
V_27 -> V_53 = 1 ;
V_27 -> V_54 = 1 ;
V_27 -> V_44 = 1 ;
}
V_37 = F_19 ( & V_7 -> V_11 , sizeof( * V_37 ) ,
V_13 ) ;
if ( ! V_37 ) {
F_25 ( V_7 , V_27 ) ;
return F_8 ( - V_14 ) ;
}
V_27 -> V_37 = V_37 ;
F_10 ( V_9 , L_38 , & V_37 -> V_55 ) ;
if ( ! V_37 -> V_55 )
V_37 -> V_55 = V_56 ;
F_10 ( V_9 , L_39 , & V_37 -> V_57 ) ;
F_10 ( V_9 , L_40 , & V_37 -> V_58 ) ;
V_37 -> V_59 = ! F_9 ( V_9 , L_41 ) ;
V_37 -> V_60 = F_9 ( V_9 , L_42 ) ;
V_37 -> V_61 = F_9 ( V_9 , L_43 ) ;
V_37 -> V_62 = F_9 ( V_9 , L_44 ) ;
V_27 -> V_63 = F_9 ( V_9 , L_45 ) ;
if ( V_27 -> V_63 ) {
V_27 -> V_44 = 0 ;
F_26 ( L_46 ) ;
}
F_10 ( V_9 , L_47 , & V_27 -> V_64 ) ;
V_27 -> V_10 = F_4 ( V_7 ) ;
return V_27 ;
}
void F_25 ( struct V_6 * V_7 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_7 -> V_11 . V_12 ;
if ( F_14 ( V_9 ) )
F_27 ( V_9 ) ;
F_7 ( V_27 -> V_30 ) ;
F_7 ( V_27 -> V_32 ) ;
}
struct V_26 *
F_20 ( struct V_6 * V_7 , const char * * V_35 )
{
return F_8 ( - V_65 ) ;
}
void F_25 ( struct V_6 * V_7 ,
struct V_26 * V_27 )
{
}
int F_28 ( struct V_6 * V_7 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_70 = F_29 ( V_7 , L_48 ) ;
if ( V_67 -> V_70 < 0 ) {
if ( V_67 -> V_70 != - V_71 ) {
F_30 ( & V_7 -> V_11 ,
L_49 ) ;
}
return V_67 -> V_70 ;
}
V_67 -> V_72 = F_29 ( V_7 , L_50 ) ;
if ( V_67 -> V_72 < 0 ) {
if ( V_67 -> V_72 == - V_71 )
return - V_71 ;
V_67 -> V_72 = V_67 -> V_70 ;
}
V_67 -> V_73 = F_29 ( V_7 , L_51 ) ;
if ( V_67 -> V_73 == - V_71 )
return - V_71 ;
V_69 = F_31 ( V_7 , V_74 , 0 ) ;
V_67 -> V_75 = F_32 ( & V_7 -> V_11 , V_69 ) ;
return F_33 ( V_67 -> V_75 ) ;
}
int F_34 ( struct V_6 * V_7 )
{
struct V_76 * V_77 = F_35 ( V_7 ) ;
struct V_78 * V_79 = F_36 ( V_77 ) ;
struct V_26 * V_27 = V_79 -> V_27 ;
int V_80 = F_37 ( & V_7 -> V_11 ) ;
if ( V_27 -> exit )
V_27 -> exit ( V_7 , V_27 -> V_81 ) ;
F_25 ( V_7 , V_27 ) ;
return V_80 ;
}
static int F_38 ( struct V_28 * V_11 )
{
int V_80 ;
struct V_76 * V_77 = F_39 ( V_11 ) ;
struct V_78 * V_79 = F_36 ( V_77 ) ;
struct V_6 * V_7 = F_40 ( V_11 ) ;
V_80 = F_41 ( V_11 ) ;
if ( V_79 -> V_27 -> exit )
V_79 -> V_27 -> exit ( V_7 , V_79 -> V_27 -> V_81 ) ;
return V_80 ;
}
static int F_42 ( struct V_28 * V_11 )
{
struct V_76 * V_77 = F_39 ( V_11 ) ;
struct V_78 * V_79 = F_36 ( V_77 ) ;
struct V_6 * V_7 = F_40 ( V_11 ) ;
if ( V_79 -> V_27 -> V_82 )
V_79 -> V_27 -> V_82 ( V_7 , V_79 -> V_27 -> V_81 ) ;
return F_43 ( V_11 ) ;
}
