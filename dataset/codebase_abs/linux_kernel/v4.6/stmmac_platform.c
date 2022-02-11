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
if ( ! V_10 )
return F_7 ( - V_14 ) ;
V_10 -> V_15 = F_8 ( V_9 , L_4 ) ;
V_10 -> V_16 = F_8 ( V_9 , L_5 ) ;
V_10 -> V_17 = F_8 ( V_9 , L_6 ) ;
V_10 -> V_18 = F_8 ( V_9 , L_7 ) ;
V_10 -> V_19 = F_8 ( V_9 , L_8 ) ;
V_10 -> V_20 = F_8 ( V_9 , L_9 ) ;
V_10 -> V_21 = F_8 ( V_9 , L_10 ) ;
F_9 ( V_9 , L_11 , & V_10 -> V_22 ) ;
F_9 ( V_9 , L_12 , & V_10 -> V_23 ) ;
F_10 ( V_9 , L_13 , V_10 -> V_24 , V_25 ) ;
return V_10 ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_8 * V_9 , struct V_28 * V_11 )
{
bool V_29 = true ;
V_27 -> V_30 = F_5 ( V_9 , L_14 , 0 ) ;
if ( V_27 -> V_30 )
F_12 ( V_11 , L_15 ) ;
if ( ! V_27 -> V_30 && F_13 ( V_9 ) ) {
if ( ( F_14 ( V_9 ) < 0 ) )
return - V_31 ;
F_12 ( V_11 , L_16 ) ;
V_27 -> V_30 = F_15 ( V_9 ) ;
V_29 = false ;
}
F_16 (np, plat->mdio_node) {
if ( F_17 ( V_27 -> V_32 , L_17 ) )
break;
}
if ( V_27 -> V_32 ) {
F_12 ( V_11 , L_18 ) ;
V_29 = true ;
}
if ( V_29 )
V_27 -> V_33 =
F_18 ( V_11 , sizeof( struct V_34 ) ,
V_13 ) ;
return 0 ;
}
struct V_26 *
F_19 ( struct V_6 * V_7 , const char * * V_35 )
{
struct V_8 * V_9 = V_7 -> V_11 . V_12 ;
struct V_26 * V_27 ;
struct V_36 * V_37 ;
V_27 = F_18 ( & V_7 -> V_11 , sizeof( * V_27 ) , V_13 ) ;
if ( ! V_27 )
return F_7 ( - V_14 ) ;
* V_35 = F_20 ( V_9 ) ;
V_27 -> V_38 = F_21 ( V_9 ) ;
if ( F_9 ( V_9 , L_19 , & V_27 -> V_39 ) )
V_27 -> V_39 = - 1 ;
V_27 -> V_40 = F_22 ( V_9 , L_20 ) ;
if ( V_27 -> V_40 < 0 )
V_27 -> V_40 = 0 ;
V_27 -> V_41 = - 1 ;
if ( F_9 ( V_9 , L_21 , & V_27 -> V_41 ) == 0 )
F_23 ( & V_7 -> V_11 , L_22 ) ;
if ( F_11 ( V_27 , V_9 , & V_7 -> V_11 ) )
return F_7 ( - V_31 ) ;
F_9 ( V_9 , L_23 , & V_27 -> V_42 ) ;
F_9 ( V_9 , L_24 , & V_27 -> V_43 ) ;
V_27 -> V_44 =
F_8 ( V_9 , L_25 ) ;
V_27 -> V_45 = V_46 ;
V_27 -> V_47 = V_3 ;
V_27 -> V_48 = 1 ;
if ( F_17 ( V_9 , L_26 ) ||
F_17 ( V_9 , L_27 ) ||
F_17 ( V_9 , L_28 ) ) {
F_9 ( V_9 , L_29 , & V_27 -> V_45 ) ;
F_9 ( V_9 , L_30 ,
& V_27 -> V_47 ) ;
F_9 ( V_9 , L_31 ,
& V_27 -> V_48 ) ;
V_27 -> V_48 = F_3 (
V_27 -> V_48 ) ;
V_27 -> V_47 = F_1 (
V_27 -> V_47 ) ;
V_27 -> V_49 = 1 ;
V_27 -> V_50 = 1 ;
}
if ( F_17 ( V_9 , L_32 ) ||
F_17 ( V_9 , L_33 ) ) {
V_27 -> V_51 = 1 ;
V_27 -> V_52 = 1 ;
V_27 -> V_44 = 1 ;
}
if ( F_24 ( V_9 , L_34 , NULL ) ) {
V_37 = F_18 ( & V_7 -> V_11 , sizeof( * V_37 ) ,
V_13 ) ;
if ( ! V_37 ) {
F_25 ( V_9 ) ;
return F_7 ( - V_14 ) ;
}
V_27 -> V_37 = V_37 ;
F_9 ( V_9 , L_34 , & V_37 -> V_53 ) ;
V_37 -> V_54 = F_8 ( V_9 , L_35 ) ;
V_37 -> V_55 =
F_8 ( V_9 , L_36 ) ;
V_37 -> V_56 =
F_8 ( V_9 , L_37 ) ;
}
V_27 -> V_57 = F_8 ( V_9 , L_38 ) ;
if ( V_27 -> V_57 ) {
V_27 -> V_44 = 0 ;
F_26 ( L_39 ) ;
}
V_27 -> V_10 = F_4 ( V_7 ) ;
return V_27 ;
}
struct V_26 *
F_19 ( struct V_6 * V_7 , const char * * V_35 )
{
return F_7 ( - V_58 ) ;
}
int F_27 ( struct V_6 * V_7 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_63 = F_28 ( V_7 , L_40 ) ;
if ( V_60 -> V_63 < 0 ) {
if ( V_60 -> V_63 != - V_64 ) {
F_29 ( & V_7 -> V_11 ,
L_41 ) ;
}
return V_60 -> V_63 ;
}
V_60 -> V_65 = F_28 ( V_7 , L_42 ) ;
if ( V_60 -> V_65 < 0 ) {
if ( V_60 -> V_65 == - V_64 )
return - V_64 ;
V_60 -> V_65 = V_60 -> V_63 ;
}
V_60 -> V_66 = F_28 ( V_7 , L_43 ) ;
if ( V_60 -> V_66 == - V_64 )
return - V_64 ;
V_62 = F_30 ( V_7 , V_67 , 0 ) ;
V_60 -> V_68 = F_31 ( & V_7 -> V_11 , V_62 ) ;
return F_32 ( V_60 -> V_68 ) ;
}
int F_33 ( struct V_6 * V_7 )
{
struct V_69 * V_70 = F_34 ( V_7 ) ;
struct V_71 * V_72 = F_35 ( V_70 ) ;
int V_73 = F_36 ( V_70 ) ;
if ( V_72 -> V_27 -> exit )
V_72 -> V_27 -> exit ( V_7 , V_72 -> V_27 -> V_74 ) ;
return V_73 ;
}
static int F_37 ( struct V_28 * V_11 )
{
int V_73 ;
struct V_69 * V_70 = F_38 ( V_11 ) ;
struct V_71 * V_72 = F_35 ( V_70 ) ;
struct V_6 * V_7 = F_39 ( V_11 ) ;
V_73 = F_40 ( V_70 ) ;
if ( V_72 -> V_27 -> exit )
V_72 -> V_27 -> exit ( V_7 , V_72 -> V_27 -> V_74 ) ;
return V_73 ;
}
static int F_41 ( struct V_28 * V_11 )
{
struct V_69 * V_70 = F_38 ( V_11 ) ;
struct V_71 * V_72 = F_35 ( V_70 ) ;
struct V_6 * V_7 = F_39 ( V_11 ) ;
if ( V_72 -> V_27 -> V_75 )
V_72 -> V_27 -> V_75 ( V_7 , V_72 -> V_27 -> V_74 ) ;
return F_42 ( V_70 ) ;
}
