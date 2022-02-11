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
struct V_5 *
F_4 ( struct V_6 * V_7 , const char * * V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 . V_12 ;
struct V_5 * V_13 ;
struct V_14 * V_15 ;
struct V_9 * V_16 = NULL ;
V_13 = F_5 ( & V_7 -> V_11 , sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 )
return F_6 ( - V_18 ) ;
* V_8 = F_7 ( V_10 ) ;
V_13 -> V_19 = F_8 ( V_10 ) ;
if ( F_9 ( V_10 , L_3 , & V_13 -> V_20 ) )
V_13 -> V_20 = - 1 ;
V_13 -> V_21 = F_10 ( V_10 , L_4 ) ;
if ( V_13 -> V_21 < 0 )
V_13 -> V_21 = 0 ;
V_13 -> V_22 = - 1 ;
V_13 -> V_23 = F_11 ( V_10 , L_5 , 0 ) ;
if ( ! V_13 -> V_23 && F_12 ( V_10 ) ) {
if ( ( F_13 ( V_10 ) < 0 ) )
return F_6 ( - V_24 ) ;
V_13 -> V_23 = F_14 ( V_10 ) ;
}
F_15 (np, child_node)
if ( F_16 ( V_16 , L_6 ) ) {
V_13 -> V_25 = V_16 ;
break;
}
if ( F_9 ( V_10 , L_7 , & V_13 -> V_22 ) == 0 )
F_17 ( & V_7 -> V_11 , L_8 ) ;
if ( ( V_13 -> V_23 && ! F_12 ( V_10 ) ) || ! V_13 -> V_25 )
V_13 -> V_26 = NULL ;
else
V_13 -> V_26 =
F_5 ( & V_7 -> V_11 ,
sizeof( struct V_27 ) ,
V_17 ) ;
F_9 ( V_10 , L_9 , & V_13 -> V_28 ) ;
F_9 ( V_10 , L_10 , & V_13 -> V_29 ) ;
V_13 -> V_30 =
F_18 ( V_10 , L_11 ) ;
V_13 -> V_31 = V_32 ;
V_13 -> V_33 = V_3 ;
V_13 -> V_34 = 1 ;
if ( F_16 ( V_10 , L_12 ) ||
F_16 ( V_10 , L_13 ) ||
F_16 ( V_10 , L_14 ) ) {
F_9 ( V_10 , L_15 , & V_13 -> V_31 ) ;
F_9 ( V_10 , L_16 ,
& V_13 -> V_33 ) ;
F_9 ( V_10 , L_17 ,
& V_13 -> V_34 ) ;
V_13 -> V_34 = F_3 (
V_13 -> V_34 ) ;
V_13 -> V_33 = F_1 (
V_13 -> V_33 ) ;
V_13 -> V_35 = 1 ;
V_13 -> V_36 = 1 ;
}
if ( F_16 ( V_10 , L_18 ) ||
F_16 ( V_10 , L_19 ) ) {
V_13 -> V_37 = 1 ;
V_13 -> V_38 = 1 ;
V_13 -> V_30 = 1 ;
}
if ( F_19 ( V_10 , L_20 , NULL ) ) {
V_15 = F_5 ( & V_7 -> V_11 , sizeof( * V_15 ) ,
V_17 ) ;
if ( ! V_15 ) {
F_20 ( V_10 ) ;
return F_6 ( - V_18 ) ;
}
V_13 -> V_15 = V_15 ;
F_9 ( V_10 , L_20 , & V_15 -> V_39 ) ;
V_15 -> V_40 =
F_18 ( V_10 , L_21 ) ;
V_15 -> V_41 =
F_18 ( V_10 , L_22 ) ;
F_9 ( V_10 , L_23 , & V_15 -> V_42 ) ;
if ( V_15 -> V_42 < 0 || V_15 -> V_42 > 256 )
V_15 -> V_42 = 0 ;
}
V_13 -> V_43 = F_18 ( V_10 , L_24 ) ;
if ( V_13 -> V_43 ) {
V_13 -> V_30 = 0 ;
F_21 ( L_25 ) ;
}
return V_13 ;
}
struct V_5 *
F_4 ( struct V_6 * V_7 , const char * * V_8 )
{
return F_6 ( - V_44 ) ;
}
int F_22 ( struct V_6 * V_7 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> V_49 = F_23 ( V_7 , L_26 ) ;
if ( V_46 -> V_49 < 0 ) {
if ( V_46 -> V_49 != - V_50 ) {
F_24 ( & V_7 -> V_11 ,
L_27 ) ;
}
return V_46 -> V_49 ;
}
V_46 -> V_51 = F_23 ( V_7 , L_28 ) ;
if ( V_46 -> V_51 < 0 ) {
if ( V_46 -> V_51 == - V_50 )
return - V_50 ;
V_46 -> V_51 = V_46 -> V_49 ;
}
V_46 -> V_52 = F_23 ( V_7 , L_29 ) ;
if ( V_46 -> V_52 == - V_50 )
return - V_50 ;
V_48 = F_25 ( V_7 , V_53 , 0 ) ;
V_46 -> V_54 = F_26 ( & V_7 -> V_11 , V_48 ) ;
return F_27 ( V_46 -> V_54 ) ;
}
int F_28 ( struct V_6 * V_7 )
{
struct V_55 * V_56 = F_29 ( V_7 ) ;
struct V_57 * V_58 = F_30 ( V_56 ) ;
int V_59 = F_31 ( V_56 ) ;
if ( V_58 -> V_13 -> exit )
V_58 -> V_13 -> exit ( V_7 , V_58 -> V_13 -> V_60 ) ;
return V_59 ;
}
static int F_32 ( struct V_61 * V_11 )
{
int V_59 ;
struct V_55 * V_56 = F_33 ( V_11 ) ;
struct V_57 * V_58 = F_30 ( V_56 ) ;
struct V_6 * V_7 = F_34 ( V_11 ) ;
V_59 = F_35 ( V_56 ) ;
if ( V_58 -> V_13 -> exit )
V_58 -> V_13 -> exit ( V_7 , V_58 -> V_13 -> V_60 ) ;
return V_59 ;
}
static int F_36 ( struct V_61 * V_11 )
{
struct V_55 * V_56 = F_33 ( V_11 ) ;
struct V_57 * V_58 = F_30 ( V_56 ) ;
struct V_6 * V_7 = F_34 ( V_11 ) ;
if ( V_58 -> V_13 -> V_62 )
V_58 -> V_13 -> V_62 ( V_7 , V_58 -> V_13 -> V_60 ) ;
return F_37 ( V_56 ) ;
}
