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
V_27 -> V_50 = 1 ;
V_27 -> V_52 = F_9 ( V_9 , L_35 ) ;
}
if ( F_18 ( V_9 , L_36 ) ||
F_18 ( V_9 , L_37 ) ) {
V_27 -> V_53 = 1 ;
V_27 -> V_54 = 1 ;
V_27 -> V_44 = 1 ;
}
if ( F_25 ( V_9 , L_38 , NULL ) ) {
V_37 = F_19 ( & V_7 -> V_11 , sizeof( * V_37 ) ,
V_13 ) ;
if ( ! V_37 ) {
F_26 ( V_7 , V_27 ) ;
return F_8 ( - V_14 ) ;
}
V_27 -> V_37 = V_37 ;
F_10 ( V_9 , L_38 , & V_37 -> V_55 ) ;
V_37 -> V_56 = F_9 ( V_9 , L_39 ) ;
V_37 -> V_57 =
F_9 ( V_9 , L_40 ) ;
V_37 -> V_58 =
F_9 ( V_9 , L_41 ) ;
}
V_27 -> V_59 = F_9 ( V_9 , L_42 ) ;
if ( V_27 -> V_59 ) {
V_27 -> V_44 = 0 ;
F_27 ( L_43 ) ;
}
F_10 ( V_9 , L_44 , & V_27 -> V_60 ) ;
V_27 -> V_10 = F_4 ( V_7 ) ;
return V_27 ;
}
void F_26 ( struct V_6 * V_7 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_7 -> V_11 . V_12 ;
if ( F_14 ( V_9 ) )
F_28 ( V_9 ) ;
F_7 ( V_27 -> V_30 ) ;
}
struct V_26 *
F_20 ( struct V_6 * V_7 , const char * * V_35 )
{
return F_8 ( - V_61 ) ;
}
void F_26 ( struct V_6 * V_7 ,
struct V_26 * V_27 )
{
}
int F_29 ( struct V_6 * V_7 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_66 = F_30 ( V_7 , L_45 ) ;
if ( V_63 -> V_66 < 0 ) {
if ( V_63 -> V_66 != - V_67 ) {
F_31 ( & V_7 -> V_11 ,
L_46 ) ;
}
return V_63 -> V_66 ;
}
V_63 -> V_68 = F_30 ( V_7 , L_47 ) ;
if ( V_63 -> V_68 < 0 ) {
if ( V_63 -> V_68 == - V_67 )
return - V_67 ;
V_63 -> V_68 = V_63 -> V_66 ;
}
V_63 -> V_69 = F_30 ( V_7 , L_48 ) ;
if ( V_63 -> V_69 == - V_67 )
return - V_67 ;
V_65 = F_32 ( V_7 , V_70 , 0 ) ;
V_63 -> V_71 = F_33 ( & V_7 -> V_11 , V_65 ) ;
return F_34 ( V_63 -> V_71 ) ;
}
int F_35 ( struct V_6 * V_7 )
{
struct V_72 * V_73 = F_36 ( V_7 ) ;
struct V_74 * V_75 = F_37 ( V_73 ) ;
struct V_26 * V_27 = V_75 -> V_27 ;
int V_76 = F_38 ( & V_7 -> V_11 ) ;
if ( V_27 -> exit )
V_27 -> exit ( V_7 , V_27 -> V_77 ) ;
F_26 ( V_7 , V_27 ) ;
return V_76 ;
}
static int F_39 ( struct V_28 * V_11 )
{
int V_76 ;
struct V_72 * V_73 = F_40 ( V_11 ) ;
struct V_74 * V_75 = F_37 ( V_73 ) ;
struct V_6 * V_7 = F_41 ( V_11 ) ;
V_76 = F_42 ( V_11 ) ;
if ( V_75 -> V_27 -> V_78 )
V_75 -> V_27 -> V_78 ( V_7 , V_75 -> V_27 -> V_77 ) ;
else if ( V_75 -> V_27 -> exit )
V_75 -> V_27 -> exit ( V_7 , V_75 -> V_27 -> V_77 ) ;
return V_76 ;
}
static int F_43 ( struct V_28 * V_11 )
{
struct V_72 * V_73 = F_40 ( V_11 ) ;
struct V_74 * V_75 = F_37 ( V_73 ) ;
struct V_6 * V_7 = F_41 ( V_11 ) ;
if ( V_75 -> V_27 -> V_79 )
V_75 -> V_27 -> V_79 ( V_7 , V_75 -> V_27 -> V_77 ) ;
else if ( V_75 -> V_27 -> V_80 )
V_75 -> V_27 -> V_80 ( V_7 , V_75 -> V_27 -> V_77 ) ;
return F_44 ( V_11 ) ;
}
